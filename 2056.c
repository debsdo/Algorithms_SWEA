//연월일 순으로 구성된 8자리의 날짜가 입력으로 주어진다.
//해당 날짜의 유효성을 판단한 후, 날짜가 유효하다면
//[그림1] 과 같이 ”YYYY / MM / DD”형식으로 출력하고,
//날짜가 유효하지 않을 경우, -1 을 출력하는 프로그램을 작성하라.
//연월일로 구성된 입력에서 월은 1~12 사이 값을 가져야 하며
//일은[표1] 과 같이, 1일 ~각각의 달에 해당하는 날짜까지의 값을 가질 수 있다.
//※ 2월의 경우, 28일인 경우만 고려한다. (윤년은 고려하지 않는다.)

//[입력]
//입력은 첫 줄에 총 테스트 케이스의 개수 T가 온다.
//다음 줄부터 각 테스트 케이스가 주어진다.

//[출력]
//테스트 케이스 t에 대한 결과는 “#t”을 찍고, 한 칸 띄고, 정답을 출력한다.
//(t는 테스트 케이스의 번호를 의미하며 1부터 시작한다.)

#include <stdio.h>

char input[12];

int main() {
   int T;
   int tc = 0;
   scanf("%d", &T);
   while (tc++ < T) {
      scanf("%s", input);

      int flag = 0;
      int year, month, day;
      year = (input[0] - 48) * 1000 + (input[1] - 48) * 100 +
         (input[2] - 48) * 10 + (input[3] - 48);
      month = (input[4] - 48) * 10 + (input[5] - 48);
      day = (input[6] - 48) * 10 + (input[7] - 48);

      while(1){
         if (month <= 0 || month > 12) {
            flag = 1;
            break;
         }
         if (month == 2) {
            if (day <= 0 || day > 28) {
               flag = 1;
               break;
            }
         }
         else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day <= 0 || day > 30) {
               flag = 1;
               break;
            }
         }
         else {
            if (day <= 0 || day > 31) {
               flag = 1;
               break;
            }
         }
         break;
      }
      
      if (flag) {
         printf("#%d -1\n", tc);
      }
      else {
         printf("#%d ", tc);
         int cnt = 0;
         int w = 0;
         while (cnt < 12) {
            if (cnt == 4 || cnt == 7) {
               printf("/");
            }
            else {
               printf("%c", input[w++]);
            }
            cnt++;
         }
         printf("\n");
      }
   }
   return 0;
}