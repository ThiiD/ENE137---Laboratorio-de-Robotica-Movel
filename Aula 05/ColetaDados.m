clc, clear all, close all

portaSerial = 'COM14';
d = zeros(250,3);
if(~exist('arduino','var'))
 arduino = configSerial(portaSerial);
 try
     nA = 50;
     r = 5;
     n = randi(255,[1,50]);
     for j = 1:length(n)
        for i= 1:r
            u(5*(j-1)+i) = n(j);
        end
     end
     
     for i=1:length(u)
         fwrite(arduino, u(i))
%          disp(u(i));
         d(i,1) = fscanf(arduino,'%u');
         disp(d(i,1));
         d(i,2) = fscanf(arduino,'%u');
         d(i,3) = fscanf(arduino,'%u');
         dT(i) = 0.1*i;
     end 
     dT = dT';
     save('t100a01','dT', 'd');
     
     fclose(arduino);
  catch
     fclose(arduino);
 end
     
end