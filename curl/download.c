#include <curl/curl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *memory;
    size_t size;
} memory;

int progress_callback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
    if (dltotal != 0) {
        fprintf(stderr, "Read %ld bytes (%.0f%%)\n", dlnow, ((double)dlnow / dltotal) * 100);
    }
    return 0;
}

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
    memory *m = (memory *)userdata;
    char *newmem = malloc(m->size + nmemb);
    memcpy(newmem, m->memory, m->size);
    memcpy(newmem + m->size, ptr, nmemb);
    free(m->memory);
    m->memory = newmem;
    m->size += nmemb;

    return nmemb;
}

char *download_url(const char *url, size_t *len) {
    CURL *handle = curl_easy_init();
    memory *m = malloc(sizeof(memory));
    m->size = 0;
    m->memory = malloc(0);

    curl_easy_setopt(handle, CURLOPT_URL, url);
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, m);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(handle, CURLOPT_NOPROGRESS, 0L);
    curl_easy_setopt(handle, CURLOPT_XFERINFOFUNCTION, progress_callback);

    int result = curl_easy_perform(handle);
    if (result != 0) {
        fprintf(stderr, "%s\n", curl_easy_strerror(result));
        return NULL;
    }

    size_t size = m->size;
    char *memory = m->memory;
    free(m);
    *len = size;
    return memory;
}

int main(int argc, char *argv[]) {
    char *url;
    if (argc > 1) {
        url = argv[1];
    } else {
        fprintf(stderr, "Please specify a URL to download!\n");
        return 1;
    }

    curl_global_init(CURL_GLOBAL_ALL);

    size_t size = 0;
    char *html = download_url(url, &size);
    if (html == NULL) return 1;
    fwrite(html, 1, size, stdout);

    curl_global_cleanup();
    return 0;
}