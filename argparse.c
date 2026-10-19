#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void usage(const char *prog)
{
    fprintf(stderr, "Використання: %s [-v] [-o вихідний_файл] <вхідний_файл>\n", prog);
    fprintf(stderr, "  -v                режим детального виводу (verbose)\n");
    fprintf(stderr, "  -o вихідний_файл файл для запису результату\n");
    fprintf(stderr, "  <вхідний_файл>    файл для обробки\n");
}

int main(int argc, char *argv[])
{
    int verbose = 0;
    const char *output_file = NULL;
    const char *input_file  = NULL;

    int opt;
    while ((opt = getopt(argc, argv, "vo:")) != -1) {
        switch (opt) {
            case 'v':
                verbose = 1;
                break;
            case 'o':
                output_file = optarg;
                break;
            default:
                usage(argv[0]);
                return EXIT_FAILURE;
        }
    }

    if (argc - optind < 1) {
        fprintf(stderr, "Помилка: не вказано вхідний файл.\n");
        usage(argv[0]);
        return EXIT_FAILURE;
    }
    input_file = argv[optind];

    if (verbose) {
        printf("Вхідний файл:  %s\n", input_file);
        printf("Вихідний файл: %s\n", output_file ? output_file : "stdout");
        printf("Verbose:       увімкнено\n");
    }

    FILE *in = fopen(input_file, "r");
    if (!in) {
        perror("Помилка відкриття вхідного файлу");
        return EXIT_FAILURE;
    }

    FILE *out = stdout;
    if (output_file) {
        out = fopen(output_file, "w");
        if (!out) {
            perror("Помилка відкриття вихідного файлу");
            fclose(in);
            return EXIT_FAILURE;
        }
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }

    fclose(in);
    if (out != stdout) {
        fclose(out);
    }

    printf("Обробка завершена.\n");
    return EXIT_SUCCESS;
}
