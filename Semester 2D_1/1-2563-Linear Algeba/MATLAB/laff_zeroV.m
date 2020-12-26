function [ x_out] = laff_zeroV(x)
if ~isvector(x)
    x_out = 'FAILED';
    return
end

x_out = zeros(size(x));

return
end

