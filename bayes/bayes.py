import numpy as np
import matplotlib.pyplot as plt

r = 50.0 #(unit:mm)
Tv = 0.05 #(unit:ms)
Oomega = 10 #(mm^2)
Gomega = 100 #(mm^2)
omega = [10.0 , 10.0]
Xo = 0.0
Yo = 0.0
x  = 0.0
y  = 0.0
X = 0.0
Y = 0.0
Xg = 0.0
Yg = 0.0
Mx = 0.0
My = 0.0
dTx = 0.0
dTy = 0.0
t = 0 #np.linspace(0, 1, 100);
x += r*np.cos(Tv*t)# + np.random.normal(0, 10)
y += r*np.sin(Tv*t)# + np.random.normal(0, 10)
X = x
Y = y
Xo = x
Yo = y
Xoo = x
Yoo = y
Mx = x
My = y

while(t<125):
	t += 1
	plt.plot(x, y,',')
	plt.plot(Mx, My,'-o')
	#plt.plot(Xo, Yo,'^')
	#plt.plot(X, Y,'o')
	Mx = 0
	My = 0
	x += r*np.cos(Tv*t)# + np.random.normal(0, 10)
	y += r*np.sin(Tv*t)# + np.random.normal(0, 10)
	dTx = r*np.cos(Tv*t) + np.random.normal(0, Oomega)
	dTy = r*np.sin(Tv*t) + np.random.normal(0, Oomega)
	Xo += dTx
	Yo += dTy
	Xoo = X + dTx
	Yoo = Y + dTy 
	k = 0
	while(k < 10):
		Xg  = x + np.random.normal(0, Gomega)
		Yg  = y + np.random.normal(0, Gomega)
		Mx += Xg
		My += Yg
		k += 1

	Mx /= 10
	My /= 10
	X = (10*omega[0]*Mx + Gomega*Xoo)/(10*omega[0] + Gomega)
	Y = (10*omega[1]*My + Gomega*Yoo)/(10*omega[1] + Gomega)
	omega[0] = (omega[0])*(Gomega)/(10*omega[0] + Gomega)
	omega[1] = (omega[1])*(Gomega)/(10*omega[1] + Gomega)
	#Mx += Xg
	#My += Yg
	#if(t%10==0):
	#	Mx /= 10
	#	My /= 10
	#	X = (10*omega[0]**2*Mx + Gomega**2*Xo)/(10*omega[0]**2 + Gomega**2)
	#	Y = (10*omega[1]**2*My + Gomega**2*Yo)/(10*omega[1]**2 + Gomega**2)
	#	omega[0] = (omega[0]**2)*(Gomega**2)/(10*omega[0]**2 + Gomega**2)
	#	omega[1] = (omega[1]**2)*(Gomega**2)/(10*omega[1]**2 + Gomega**2)

plt.show()
print(omega[0])
