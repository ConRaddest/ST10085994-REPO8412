function D = PerturbAndObserve(Vpv,Ipv)

% Declare persistent variables to check changes in power
persistent Dprev Pprev Vprev; 

% Intiliase for first call of function
if isempty(Pprev)
    Dprev = 0.7;
    Vprev = 190;
    Pprev = 2000;
end

deltaD = 125e-6;

Ppv = Vpv*Ipv;

% following flow diagram
if Ppv ~= Pprev
    if Ppv > Pprev
        if Vpv > Vprev
            D = Dprev - deltaD;
        else
            D = Dprev + deltaD;
        end
    else
        if Vpv > Vprev
            D = Dprev + deltaD;
        else
            D = Dprev - deltaD;
        end
    end
end

Dprev = D;
Vprev = Vpv;
Pprev = Ppv;