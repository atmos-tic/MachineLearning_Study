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
Osigma = 50 #(mm^2)
Gsigma = 100 #(mm^2)
sigma = [0.0 , 0.0]
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
t = 0 
x += r*np.cos(Tv*t)
y += r*np.sin(Tv*t)
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

while(t<100):
	t += 1
	ims_x.append(x)
	ims_y.append(y)
	ims_Xo.append(Xo)
	ims_Yo.append(Yo)
	ims_X.append(X)
	ims_Y.append(Y)
	#im1.append(plt.plot(x, y, '.',c="r",label="true"))
	#im3.append(plt.plot(Xo, Yo, '^', c="y",label="odometry"))
	#im4.append(plt.plot(X, Y, 'o', c="b",label="estimate"))
	Mx = 0
	My = 0
	x += r*np.cos(Tv*t)
	y += r*np.sin(Tv*t)
	dTx = r*np.cos(Tv*t) + np.random.normal(0, Osigma)
	dTy = r*np.sin(Tv*t) + np.random.normal(0, Osigma)
	Xo += dTx
	Yo += dTy
	Xoo = X + dTx
	Yoo = Y + dTy 
	sigma[0] = (sigma[0])+(Osigma)
	sigma[1] = (sigma[1])+(Osigma)
	k = 0
	while(k < 10):
		Xg  = x + np.random.normal(0, Gsigma)
		Yg  = y + np.random.normal(0, Gsigma)
		ims_Xg.append(Xg)	
		ims_Yg.append(Yg)	
		#im2.append(plt.plot(Xg, Yg, '+', c = "g",label="GPS"))
		Mx += Xg
		My += Yg
		k += 1
	Mx /= 10
	My /= 10
	X = (10*sigma[0]*Mx + Gsigma*Xoo)/(10*sigma[0] + Gsigma)
	Y = (10*sigma[1]*My + Gsigma*Yoo)/(10*sigma[1] + Gsigma)
	sigma[0] = (sigma[0])*(Gsigma)/(10*sigma[0] + Gsigma)
	sigma[1] = (sigma[1])*(Gsigma)/(10*sigma[1] + Gsigma)
	Dg += ((x-Mx)**2+(y-My)**2)
	Do += ((x-Xo)**2+(y-Yo)**2)
	D += ((x-X)**2+(y-Y)**2)
	# ims.append(plt.plot(ims_x,ims_y,'.',c="r",label="true"))
	# ims.append(plt.plot(ims_Xo,ims_Yo,'^', c="yellow",label="odometry"))
	# ims.append(plt.plot(ims_Xg,ims_Yg, '+', c="g",label="GPS"))
	# ims.append(plt.plot(ims_X,ims_Y, 'o', c="b",label="estimate"))
	# plt.legend()
	ani = animation.ArtistAnimation(fig, ims, interval=50, repeat_delay=100)

plt.plot(ims_x,ims_y,'.',c="r",label="true")
plt.plot(ims_Xo,ims_Yo,'^', c="yellow",label="odometry")
plt.plot(ims_Xg,ims_Yg, '+', c="g",label="GPS")
plt.plot(ims_X,ims_Y, 'o', c="b",label="estimate")

#plt.show()
#ani = animation.ArtistAnimation(fig, ims, interval=50, repeat_delay=100)
#ani.save('anim.gif', writer="imagemagick")
plt.legend()
plt.show()
print(sigma[0])
print(Dg/600)
print(Do/600)
print(D/600)