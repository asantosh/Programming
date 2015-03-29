#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef struct variable {
    char name;
    float value;
} variable_t;

/* Core of the algorithm resides in this function.
 * Hence care has to be taken for scalability and addition of a new
 * logics if any in fu*/
int parse_formula(char *str, variable_t *data)
{
    char *formula = strdup(str);
    
    	


    free(formula);
    return EXIT_SUCCESS;
}

int parse_value(variable_t *var, char *str)
{
    char *tstr;
    var->name = str[0];
    tstr = strstr(str, "=");
    if (tstr == NULL) {
	printf("[ %s ]\t", str); 
	return EXIT_FAILURE;
    }
    tstr++;
    var->value = atof(tstr);

    return EXIT_SUCCESS;
}

/* Print error and help message */
void print_err(void)
{
    printf("Invalid Options\n");
}

/* main parser */
int main_parser(int argc, char *argv[])
{
    unsigned int count = 0;
    unsigned char t_args;
    char *formula;
    variable_t data[5];

    formula = argv[1]; /* 1st arg is the formula */
    printf("%s\n", formula);

    t_args = argc - 2; /* 1st two will be the exe name and the formula */
    while (count < t_args) {
	/* value of variables will start with 2rd arg in argv[] */
	if (parse_value(&data[count], argv[count + 2]) == EXIT_FAILURE)
	    goto error;
	
	printf("%c = %g\n", data[count].name, data[count].value);
	count++;
    } 
   
    /* Substitue the value of the variables in the formula, compute and print
     * the output */

    parse_formula(formula, data);

    return EXIT_SUCCESS;
error:
    print_err();
    return EXIT_FAILURE;
}

/* Main driver function */
int main(int argc, char *argv[])
{
    if (argc < 2) { /* No cmd_line arguments, hence return */
	print_err();
	return EXIT_FAILURE;
    }

    main_parser(argc, argv);

    return EXIT_SUCCESS;
}
