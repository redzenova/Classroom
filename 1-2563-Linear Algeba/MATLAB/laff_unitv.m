function [y_out] = laff_unitv(x, e) 

y_out = laff_zeroV(x);
y_out(e) = 1;

end

