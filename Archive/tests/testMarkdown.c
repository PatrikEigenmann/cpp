#include "../mylibs/markdown.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Callback to handle the HTML output
static void output_callback(const char* output, unsigned int size, void* userdata) {
    fwrite(output, 1, size, stdout); // Print the generated HTML
}

int main() {
    const char* markdown = "# Hello markdown!\n\n ## Suptitle \n\nThis is a simple markdown example.\n\n- Item 1\n- Item 2\n- Item 3\n";
    
    // Call md_html to convert the markdown to HTML
    int result = md_html(markdown, strlen(markdown), output_callback, NULL, 0, 0);


    if (result != 0) {
        fprintf(stderr, "Error: Failed to convert Markdown to HTML.\n");
        return 1;
    }

    return 0;
}