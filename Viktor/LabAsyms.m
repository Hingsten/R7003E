syms mw lw mb lb g Iw Im            % Constants
syms Ft Fx Fy Tm Tf N               % Forces
syms xw(t) tw(t) xb(t) yb(t) tb(t)  %Coordinates / angles
%xw
dxw = diff(xw,t);
ddxw = diff(dxw,t);
%xb
dxb = diff(xb,t);
ddxb = diff(dxb,t);
%yb
dyb = diff(yb,t);
ddyb = diff(dyb,t);
%tw(aka theta wheel)
dtw = diff(tw,t);
ddtw = diff(dtw,t);
%tb
dtb = diff(tb,t);
ddtb = diff(dtb,t);

%Equations stemming from the wheel
Fy = mw*g+N %forces in y direction
Fx = Ft-mw*ddxw %Forces in x direction
Ft = (Tm-Tf-Iw*ddtw)/lw
