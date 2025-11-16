const int M = 1e9+7;
int  numSub(string S){
int res =0;
int cnt =0;

 for(char ch:s){
 if ( ch == '1'){
  cnt++;
// so we are basically adding natural number to the sum so it returns crct op
  res = (res+cnt)%M;
 }
 else {
  cnt =0;
 }
 }

 return res;
 }
