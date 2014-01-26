#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>



int main(int argc, char **argv) {

    const char *short_options = "hl:a:";

    const static struct option long_options[] = {
        {"lst", required_argument, NULL, 'l'},
        {"add", no_argument, NULL, 'a'},
        {"help", no_argument, NULL, 'h'},
        {NULL, 0, NULL, 0}
    };

    int option_index;
    int c;
    while ((c = getopt_long(argc, argv, short_options, 
                    long_options, &option_index)) != -1) {
        switch (c) {
            case 'h':
                printf("option_index = %d (\"%s\", %d, %c)\n",
                        option_index,
                        long_options[option_index].name,
                        long_options[option_index].has_arg,
                        long_options[option_index].val);
                break;
            case 'l':
                printf("option l with arg %s\n", optarg);
                break;
            case 'a':
                printf("option a with arg %s\n", optarg);
                break;
            case '?':
                printf("unknown option\n");
                break;
            default:
                printf("?? getopt returned character code 0%o ??\n", c);
        }
    }

    if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc) 
            printf("%s ", argv[optind++]);
        printf("\n");
    }

    return(EXIT_SUCCESS);
}
