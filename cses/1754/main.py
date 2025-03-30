for _ in[0]*int(input()):
    a,b=sorted(map(int,input().split()))
    print("NO"if(b-2*a)%3or b>2*a else"YES")
  
