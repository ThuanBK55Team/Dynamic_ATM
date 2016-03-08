#include <stdio.h>
#include "createTestcase.h"

#define INF 1000001
int Value[50];
long Withdraw;
long F[50][1000001];

long min(long a, long b){
	return ((a<b) ? a : b);
}
int main(void)
{
	createTestcase(50);
	freopen("input.txt", "r", stdin);
	int test_case, NT;
	scanf("%d", &NT);
	for (test_case = 1; test_case <= NT; test_case++)
	{
		int i, N;
		long j;
		int Case_Number;
		scanf("%d", &Case_Number);
		scanf("%d", &N);
		for (i = 1; i <= N; i++)scanf("%d", &Value[i]);
		scanf("%ld", &Withdraw);

		for (j = 1; j <= Withdraw; j++)
			F[1][j] = j%Value[1] ? INF : j / Value[1];

		for (i = 2; i <= N; i++){
			for (j = 1; j <= Withdraw; j++){
				if (j<Value[i]) F[i][j] = F[i - 1][j];
				else F[i][j] = min(F[i - 1][j], F[i][j - Value[i]] + 1);
			}
		}
		if (F[N][Withdraw] >= INF)printf("Case #%d Impossible\n", test_case);
		else printf("Case #%d %ld\n", test_case, F[N][Withdraw]);
	}
	return 0;
}