/*
필요한 것들
(크기), {맵} 입력받기
 (현재 단지) 변수
 보는건 상관 X
 한줄을 돌고 1만나면 시작 ~0만나면 (단지수)+1  끝까지 
 한줄 내려가면 (시작단지수)로 초기화 
 1번째줄부터 돌면서 위아래줄까지 체크하고
  2번째줄부턴  1+(단지수) 
단지별 집 수는 다 돌고 계산 
+모양으로 계산하기 

 


계산할때는 1인 값에 단지수 더하기 
0 : 빈칸 
1 : 계산안된 집
2 : 1번째 단지의 집
3 : 2번째 단지의 집
4 : 3번째 단지의 집 

단지수 = 집 - 1
 
*/
#include <stdio.h>
#define DANJI_SIZE 315

int main(void){
  int size, i, j, ii, danjisu, up, start, last, home; //기본 선언  
  int danji[DANJI_SIZE], danji2[DANJI_SIZE]; //1개만 있는 집은 단지로 안칠때 최대크기가 25, 세로로 2칸씩은 뭉쳐야 하니까 25 / 2 = 12근처,
  // 가로로 1칸씩은  떨어져야 하니까 25 / 2 해서  12 * 12 = 144이기 때문에 200은 넘지 않을거 같음(실제론 약 162개) 
  printf("size >>");
  scanf("%d", &size); //맵크기 입력받기 
  char map1[size];
  int map2[size][size]; //맵 선언  
  
    
  for(i=0;i<size;i++){
    printf("map >>");
      scanf("%s", map1);
      for(j=0;j<size;j++){
          map2[i][j] = map1[j] - '0';
      }
  } //맵 입력받기  
  

 
  /*
for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      printf("%d/", map2[i][j]);
    }
    printf("\n");
  } //맵 출력 코드 

 for(danjisu=1;1;danjisu++){
    for(i=0;i<size;i++){
      for(j=0;j<size;j++){
        if(map2[i][j] == danjisu){
          if(a > j)
            a = j;
          map2[i][j] += danjisu;
          danji[danjisu]++;
        }
        else if(map2[i][j] == 0){
          if(j > a)
            break;
        }
      }
      
    }
  } // 전 계산코드 
*/ 
danjisu = start = 1;
  for(ii=0;ii<30;ii++){ //한번에 제대로 측정 안될수도 있어서 넣은 반복 
    for(i=0;i<size;i++){ //세로줄 반복 
        for(j=0;j<size;j++){ //가로줄 반복 
	    	if (map2[i][j] == 1){ //현재 칸이 단지에 포함 안된 집이면 단지수를 더해서 단지에 포함 
	    		map2[i][j] += danjisu; 
			}else if(map2[i][j] == 0 && up == 1){ //0을 만나면 단지수를 1 증가시킴 
				danjisu++;
				up = 2; //다시 집을 만나지 않으면 더 올라가지 않게 
			}
			if(map2[i][j] >= 2){ //단지에 포함된 집이면 +모양의 근처의 집이 자신보다 단지수가 높으면 자신의 단지로 만들기 
				last = map2[i][j];
				if(i > 0){
				if(last < map2[i-1][j] && map2[i-1][j] >= 1){
					map2[i-1][j] = last;
					up = 1;
				}
			}
				if(i < size-1){
				if(last < map2[i+1][j] && map2[i+1][j] >= 1){
					map2[i+1][j] = last;
					up = 1;
				}
			}
				if(j < size-1){
				if(last < map2[i][j+1] && map2[i][j+1] >= 1){
					map2[i][j+1] = last;
					up = 1;
				}
			}
				if(j > 0){
				if(last < map2[i][j-1] && map2[i][j-1] >= 1){
					map2[i][j-1] = last;
					up = 1;
				}
			}
			}
      }
      //danjisu = 1;
    }
    //danjisu = 1;
  }


  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      printf("%d/", map2[i][j]);
    }
    printf("\n");
  } //맵 출력코드  
  
  for(i=0;i<DANJI_SIZE -1;i++){
  	danji[i] = 0;
  } //단지내 집 수 0으로 초기화 
  
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      danji[map2[i][j]] += map2[i][j];
    }
  } //단지내 집 수 넣는 코드 
  
  
  
  
  for(i=0;i<DANJI_SIZE -1;i++){
  	if(danji[i] > 0){ 
  	danji2[i] = danji[i] / i; //단지수로 나눠서 집 수 계산 
  	home++; //총 단지수 계산 
  	printf("%d/", danji2[i]);
	  }
  } //단지내 집 수 계산 
  
  printf("\n%d", home); //총 단지수 출력 
  
  
  
  
  
  return 0;
} 

