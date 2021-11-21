#include <stdio.h>
 
int main()
{
	//나눠 떨어졌는지 확인하기 위한 변수(Div: divisor 약수를 줄임) 
	int hasDiv = 0;
 
	//1은 소수가 아니므로 생략
	for (int n = 2; n <= 5000; n++)
	{
		//(위에 제시한 방법) 1보다 크고 n보다 작은 숫자로 나눠 떨어지는지 확인
		for (int div = 2; div < n; div++)
		{
			//나눠 떨어졌으면 1과 n사이의 수인 약수가 있다는 말이다. hasDiv변수를 true로 설정해주자.
			if (n % div == 0) {
				hasDiv = 1;
				//이미 소수가 아닌 것을 확인했으므로 루프 탈출 
				break;
			}
		}
 
		//약수가 없으면 소수이므로 출력
		if (!hasDiv)
		{
			//소수 출력
			printf("%d\n", n);
		}
 
		//hasDiv 초기화
		hasDiv = 0;
	}
 
	return 0;
}
