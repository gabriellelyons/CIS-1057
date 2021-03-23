#include <stdio.h>
#include <stdlib.h>

int is_substance_within_x_percent();

int main()
{
	double substance, data;
	int result;

	printf("Enter an unknown boiling point: ");
	scanf("%lf", &data);
        printf("Enter a known boiling point: ");
        scanf("%lf", &substance);

	result = is_substance_within_x_percent(substance, data, 0.03);

	printf("The result is %d.\n", result);
}

int is_substance_within_x_percent(double substance, double data, double percent)
{
        if (( substance - percent * substance <= data) &&
                ( substance + percent * substance >= data))
                return 1;
        else
                return 0;
}


