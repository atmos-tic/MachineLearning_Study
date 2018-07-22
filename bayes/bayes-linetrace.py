import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig = plt.figure()
ims = []
ims_x = []
ims_y = []
ims_X = []
ims_Y = []
ims_Xg = []
ims_Yg = []
ims_Xo = []
ims_Yo = []

r = 100.0 #(unit:mm)
Tv = 0.064 #(unit:ms)
Osigma = 5 #(mm^2)
Lsigma = 5 #(mm^2)
sigma = [0.0 , 0.0]
LLLsigma = 5
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
ddTx = 0.0
ddTy = 0.0
lx = np.linspace(0, 100000, 100000)
ly = lx*0
t = 0 
x = np.random.normal(0, LLLsigma)
y = np.random.normal(0, LLLsigma)
X = x
Y = y
Xo = x
Yo = y
Xoo = x
Yoo = y
Mx = x
My = y
Dg = 0.0
Do = 0.0
D = 0.0

while(t<1000):
	t += 1
	ims_x.append(x)
	ims_y.append(y)
	ims_Xo.append(Xo)
	ims_Yo.append(Yo)
	ims_X.append(X)
	ims_Y.append(Y)
	ims_Xg.append(Xg)	
	ims_Yg.append(Yg)	
	Mx = 0
	My = 0
	dTx = r+ np.random.normal(0, LLLsigma)
	dTy = -y*r/1000 + np.random.normal(0, LLLsigma)
	x += dTx
	y += dTy
	ddTx = dTx + np.random.normal(0, Osigma)
	ddTy = dTy + np.random.normal(0, Osigma)
	Xo += ddTx
	Yo += ddTy
	Xoo = X + ddTx
	Yoo = Y + ddTy 
	Xg  = x
	Yg  = y+np.random.normal(0, Lsigma)
	sigma[0] = (sigma[0])+(Osigma)
	sigma[1] = (sigma[1])+(Osigma)
	X = (sigma[0]*Xg + Lsigma*Xoo)/(sigma[0] + Lsigma)
	Y = (sigma[1]*Yg + Lsigma*Yoo)/(sigma[1] + Lsigma)
	sigma[0] = (sigma[0])*(Lsigma)/(sigma[0] + Lsigma)
	sigma[1] = (sigma[1])*(Lsigma)/(sigma[1] + Lsigma)
	Dg += ((x-Xg)**2+(y-Yg)**2)
	Do += ((x-Xo)**2+(y-Yo)**2)
	D += ((x-X)**2+(y-Y)**2)
	# ims.append(plt.plot(ims_x,ims_y,'.',c="r",label="true"))
	# ims.append(plt.plot(ims_Xo,ims_Yo,'^', c="yellow",label="odometry"))
	# ims.append(plt.plot(ims_Xg,ims_Yg, '+', c="g",label="GPS"))
	# ims.append(plt.plot(ims_X,ims_Y, 'o', c="b",label="estimate"))
	# plt.legend()
	ani = animation.ArtistAnimation(fig, ims, interval=50, repeat_delay=100)

plt.plot(lx, ly, c="black", label="line")
plt.plot(ims_x,ims_y,'.',c="r",label="true")
plt.plot(ims_Xo,ims_Yo,'.', c="yellow",label="odometry")
#plt.plot(ims_Xg,ims_Yg, '+', c="g",label="line")
plt.plot(ims_X,ims_Y, '+', c="b",label="estimate")

#plt.show()
#ani = animation.ArtistAnimation(fig, ims, interval=50, repeat_delay=100)
#ani.save('anim.gif', writer="imagemagick")
plt.legend()
plt.show()
print(sigma[0])
print(Dg/600)
print(Do/600)
print(D/600)