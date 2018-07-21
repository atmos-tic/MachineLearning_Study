import numpy as np
import matplotlib.pyplot as plt

r = 10.0 #(unit:mm)
Tv = 0.01 #(unit:ms)
Oomega = 5 #(mm^2)
Gomega = 80 #(mm^2)
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
t = 0 #np.linspace(0, 1, 100);
x += r*np.cos(Tv*t)# + np.random.normal(0, 10)
y += r*np.sin(Tv*t)# + np.random.normal(0, 10)
X = x
Y = y
Xo = x
Yo = y
Yg  = y + np.random.normal(0, Gomega)
Xg  = x + np.random.normal(0, Gomega)
while(t<600):
	t += 1
	plt.plot(x, y,',')
	#plt.plot(Xg, Yg,'o')
	plt.plot(Xo, Yo,'-o')
	plt.plot(X, Y, 'o')
	x += r*np.cos(Tv*t)# + np.random.normal(0, 10)
	y += r*np.sin(Tv*t)# + np.random.normal(0, 10)
	Yg  = y + np.random.normal(0, Gomega)
	Xg  = x + np.random.normal(0, Gomega)
	Xo += r*np.cos(Tv*t) + np.random.normal(0, Oomega)
	Yo += r*np.sin(Tv*t) + np.random.normal(0, Oomega)
	Mx += Xg
	My += Yg
	if(t%10==0):
		Mx /= 10
		My /= 10
		X = (10*omega[0]**2*Mx + Gomega**2*Xo)/(10*omega[0]**2 + Gomega**2)
		Y = (10*omega[1]**2*My + Gomega**2*Yo)/(10*omega[1]**2 + Gomega**2)
		omega[0] = (omega[0]**2)*(Gomega**2)/(10*omega[0]**2 + Gomega**2)
		omega[1] = (omega[1]**2)*(Gomega**2)/(10*omega[1]**2 + Gomega**2)

plt.show()
