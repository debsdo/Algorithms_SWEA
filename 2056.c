#include <stdio.h>

int main() {
    int T, tc = 0;
    scanf("%d", &T);
    
    while (tc++ < T) {
        int inNum, yr, mt, dt;
        scanf("%d", &inNum);
        yr = inNum / 10000;
        mt = (inNum % 10000) / 100;
        dt = (inNum % 10000) % 100;
        
        int flag = 0;

        while(1){
            if (mt <= 0 || mt > 12) {
                flag = 1;
                break;
			}
            if (mt == 2) {
                if (dt <= 0 || dt > 28) {
                    flag = 1;
                    break;
                }
            }
            else if (mt == 4 || mt == 6 || mt == 9 || mt == 11) {
                if (dt <= 0 || dt > 30) {
                    flag = 1;
                    break;
				}
			}
			else {
				if (dt <= 0 || dt > 31) {
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
          printf("#%d %04d/%02d/%02d\n", tc, yr, mt, dt);
	  }
   }
   return 0;
}