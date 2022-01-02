https://practice.geeksforgeeks.org/problems/run-length-encoding/1/
string encode(string src)
{     
  string temp="";
  int count=1;
   temp+=src[0];
  for(int i=1;i<src.length();i++){
      if(src[i]==src[i-1])
      count++;
      else{
      temp+=to_string(count)+src[i];
      
      count=1;
  }
}  temp+=to_string(count);
  return temp;
}    