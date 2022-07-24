function [] = sendVelocity(vE,vD)
vD = single(vD);
vE = single(vE);

vDarray = typecast(vD,'uint8');
vEarray = typecast(vE,'uint8');

msg = [ 1 vDarray vEarray ];

for i=1:length(msg)
    fwrite(arduino, msg(i));
end
end

