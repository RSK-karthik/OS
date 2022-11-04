

N = int(input("No of processes: "))
p = []
for i in range(N):
    at = int(input("Enter arrival time of {}th process: ".format(i)))
    bt = int(input("Enter burst time of {}th process: ".format(i)))
    p.append([at,bt])
p.sort(key=lambda x: x[0])
wt = [0]*N
wt[0] = 0
tat = [0]*N
tat[0] = 0
print("P.No.\tArrival Time\t" , "Burst Time\tWaiting Time\t Turn Around Time")
print("1" , "\t\t" , p[0][0] , "\t\t" , p[0][1] , "\t\t" , wt[0],"\t\t",tat[0])
for i in range(1,5):
    wt[i] = (p[i - 1][0] + p[i - 1][1] + wt[i - 1]) - p[i][0]
    tat[i] = p[i][1]+wt[i]
    print(i + 1 , "\t\t" , p[i][0] , "\t\t" , p[i][1] , "\t\t" , wt[i],"\t\t",tat[i])
average = 0.0
sum_wt = 0 
sum_tat = 0
for i in range(5):
    sum_wt = sum_wt + wt[i]
    sum_tat += tat[i]

print("Average waiting time = " , sum_wt/N)
print("Average Turn around time = ",sum_tat/N)
