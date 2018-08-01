// https://www.hackerrank.com/challenges/variable-sized-arrays/problem

#include <stdio.h>

struct query
{
	int arr_no, arr_index;
};

int main()
{
	unsigned long long p, q, size;

	scanf("%llu %llu", &p, &q);

	int *my_arrs[p];

	for (int i = 0; i < p; i++)
	{
		scanf("%llu", &size);

		my_arrs[i] = new int[size];

		for (int j = 0; j < size; j++)
			scanf("%d", &my_arrs[i][j]);
	}

	struct query *my_queries[q];

	for (int i = 0; i < q; i++)
	{
		my_queries[i] = new query();
		// printf("\nscanning\n");
		scanf("%d %d", &my_queries[i]->arr_no, &my_queries[i]->arr_index);
	}

	for (int i = 0; i < q; i++)
		printf("%d \n", my_arrs[my_queries[i]->arr_no][my_queries[i]->arr_index]);

	return 0;
}