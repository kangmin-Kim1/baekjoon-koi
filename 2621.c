/*
1 색깔 전부같 + 숫자 연속적 -> 1&2
2 숫자 4장같 -> 3
3 숫자 3장같 + 숫자 2장같 -> 4&5 
4 색깔 전부같 -> 1
5 숫자 연속적 -> 2
6 숫자 3장같 -> 4
7 숫자 2장같 + 숫자 2장같 -> 5&5
8 숫자 2장같 -> 5
9 위 전부 해당 아닐때 -> X


1 <- 4/5
4or5 중 하나에서 해당이면 나머지 하나 검사후 1 보내기
나머지 하나는 걍 ㄱㄱ
 
7 <- 3 <- 8
숫자 2장같이면 3장같or2장같인지 확인후 아니면 나머지 확인후 2실행
 
2, 6,
대충 

필요한 조건
1.색깔 전부같? 첫번째 카드 색깔 저장 후 2~4 돌면서 색 다르면 반복 종료, 끝까지 도달 시 조건 만족 
2.숫자 연속적? ->가장작은수 확인후  +1인 수or9일경우 1이 있는지 탐색 -> 없으면 종료, 있으면 반복 후 5번 도달 시 조건 만족  
3.숫자 4장같? -> 넘버2에서 측정, 1번카드부터 카드와 수가 같으면 0으로 만들고 카운트 +1 
4.숫자 3장같?
5.숫자 2장같? 

규칙 중복시 점수가 더 높은것만 적용이니 if else~ 
*/

#include <stdio.h>

int main(void){
	int i, j, a,b,c,d,e, min, max, testnum, test, same, score;
	b = c = d = e = 0;
	a = 1;
	char colortest;
	int number[5], save[4]; //넘버2는 같은수 확인계산용, same은 같은 수  
	char color[5];
	
	for(i=0;i<5;i++){
		save[i] = 0;
	}
	//printf("R B Y G / 1~9\n"); //입력해야할 것 
	for(i=0;i<5;i++){
		scanf(" %c %d", &color[i], &number[i]);
	} //카드 입력 
	/*
	for(i=0;i<5;i++){
		printf("%c/%d\n", color[i], number[i]);
	} //출력용  
	*/
	colortest = color[0];
	for(i=0;i<5;i++){  //조건1(색깔이 전부 같은가?) 
		if(colortest != color[i]){
			a--;
		}
	}
	//1 이상이면 조건 만족 -> --에 한번이라도 걸리면 0이 되는 구조 
	
	min = number[0]; //첫번째 수가 기본적으로 가장 작게 설정 
	for(i=1;i<5;i++){ //가장 작은 수 측정 (첫번째 수는 측정하지 않음) 
		if(min > number[i]){
			min = number[i];
		}
	}
	
	max = number[0]; //가장 작은 수 측정하는김에 같이 가장 큰 수도 측정(원리같음) 
	for(i=1;i<5;i++){
		if(max < number[i]){
			max = number[i];
		}
	}
	
	testnum = min;
	test = 1;
	//9 1 2 3 4도 연속적인지는 모르지만 일단 그렇다고 가정하고 작성한 코드 
	for(i=0;i<5&&test >= 1;i++){ //조건2(수가 연속적인가?) 
		if(testnum == 9){
			testnum = 1;
		}else{
			testnum++;
		} //다음 수가 몇이어야 연속적인지 측정
		
		test = 0; //test를 0으로 초기화(test가 0 이하면 반복 종료) 
		for(j=0;j<5;j++){
			if(testnum == number[j]){
				test++; //연속적인 수 발견 시 test 증가로 반복 지속 
			}
		}
	}

	if(i == 5){
			b = 1;//반복 5번 후 종료까지 연속적이면 조건 달성 
		} 
		
		
	for(i=0;i<5;i++){ //조건 3,4,5(카드 n장이 서로 숫자가 같은가?) 
		if(number[i] > 0){ //숫자가 0(수가 같아서 제외됨)이면 실행하지 않음 
			test = number[i]; //귀찮음 해결용 변수 재활용
			number[i] = 0; //확인했으니 제외? 
			same = 1; //초기화 
			for(j=0;j<5;j++){
				if(i != j){ //자신과 자신의 숫자가 같음 방지용 
					if(number[j] == test){
						number[j] = 0; //숫자가 같으니 제외 
						same++; //n장이 숫자가 같음에서 n에 +1 
					}
				}
			}
			
			switch(same){ //2장 이상 같을 시 조건 만족 
				case 4 :
					c++;
					save[3] = test;
					break;
					
				case 3 :
					d++;
					save[2] = test;
					break;
					
				case 2 :
					e++;
					if(save[0] >= 1){
						save[1] = test;
					}else{
						save[0] = test;
					}
					break;
			}
		}
	}
	
	if (a >= 1 && b >= 1){ //1번 
		score = 900 + max;
	} else if(c >= 1){ // 2번 
		score = 800 + save[3]; //버그 방지용 0, 실제로는 같은 수를 더해야 함 
	} else if(d >= 1 && e >= 1){ //3번 
		score = 700 + (save[2] * 10) + save[0]; //버그 방지용 0, 실제로는 생략 
	} else if(a >= 1){ //4번 
		score = 600 + max;
	} else if(b >= 1){ //5번 
		score = 500 + max;
	} else if(d >= 1){ //6번 
		score = 400 + save[2];
	} else if(e >= 2){ //7번 
		if(save[0] >= save[1]){
			score = 300 + (save[0] * 10) + save[1];
		}else{
			score = 300 + (save[1] * 10) + save[0];
		}
	} else if(e >= 1){ //8번 
		score = 200 + save[0];
	} else{ //9번 
		score = 100 + max;
	}
	/*
	for(i=0;i<5;i++){
		printf("%c/%d, %d\n", color[i], number[i], number2[i]);
	}
//	printf("min = %d\n", min);
//	printf("%d %d %d %d %d\n", a,b,c,d,e);
//	printf("score = %d", score);*/
	printf("%d", score);
	return 0;
}
