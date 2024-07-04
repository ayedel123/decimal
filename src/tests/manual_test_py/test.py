from decimal import Decimal
with open('tests/manual_test_py/test_data.txt', 'r') as file:
    lines = file.readlines()
    for line in lines:
        s = line.strip() 

        sign = -1 if s[0] == "1" else 1

        num2 = (int(s[8:16], 2))

        num1 = (int(s[32:128], 2))

        print('scale: ',num2,'val: ',int((sign * num1)/(10**num2)),num1%(10**num2),"tru: ",num1)
               # if(num2>28):
            #print("error:num2 = ",num2)
    
        #if (k ==0):
         #   a=sign * num1/10**num2
       # if (k ==3):
         #   b=sign * num1/10**num2
       # k+=1
#print('a: {:.2f}'.format(a))
#print('b: {:.2f}'.format(b))
#print('{:.2f}'.format(a-b*10))