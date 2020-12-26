function [y_out] = laff_zeroM(A)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

[r,c] = size(A);
for i = 1:r
    for j = 1:c
        y_out(i, j) = 0;
    end
end

end

