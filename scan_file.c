#include <stdio.h>
#include <stdlib.h>
#include <clamav.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_to_scan>\n", argv[0]);
        return 1;
    }

    if (cl_init(CL_INIT_DEFAULT) != CL_SUCCESS) {
        fprintf(stderr, "Failed to initialize ClamAV\n");
        return 1;
    }

    struct cl_engine *engine = cl_engine_new();
    if (!engine) {
        fprintf(stderr, "Failed to create new engine\n");
        return 1;
    }

    unsigned int sigs = 0;
    if (cl_load(cl_retdbdir(), engine, &sigs, CL_DB_STDOPT) != CL_SUCCESS) {
        fprintf(stderr, "Failed to load ClamAV DB\n");
        cl_engine_free(engine);
        return 1;
    }

    if (cl_engine_compile(engine) != CL_SUCCESS) {
        fprintf(stderr, "Failed to compile ClamAV engine\n");
        cl_engine_free(engine);
        return 1;
    }

    const char *virname;
    int result = cl_scanfile(argv[1], &virname, NULL, engine,0);

    if (result == CL_VIRUS) {
        printf("Infected: %s\n", virname);
    } else if (result == CL_CLEAN) {
        printf("Clean\n");
    } else {
        printf("Error scanning file\n");
    }

    cl_engine_free(engine);
    return 0;
}