import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
target=1
kp=1.2
ki=0.3
kd=0.1
step=100
y=0
y_next=0
u=0
error=0
prev_error=0
e_sum=0
p_out=0
i_out=0
d_out=0
d_err=0
k=0
k_list=[]
y_list=[]
error_list=[]
u_list=[]
for i in range(step):

    error=target-y
    e_sum=e_sum+error
    d_err=error-prev_error
    u=kp*error+ki*e_sum+kd*d_err
    y_next=0.8*y+0.2*u
    y=y_next
    prev_error=error
    k_list.append(k)
    y_list.append(y)
    u_list.append(u)
    error_list.append(error)
    k=k+1

#画图
plt.plot(k_list,y_list)
plt.title('PID Controller')
plt.xlabel('time_step')
plt.ylabel('output')
plt.xlim(0,100)
plt.grid(True)
plt.savefig('PID-response.png',dpi=300)
plt.show()


#制表
pid_data=pd.DataFrame({
    'time_step':k_list,
    'output':y_list,
    'error':error_list,
    'control_input':u_list,

})
pid_data.to_csv('pid_data.csv')
# print(data)