function [y_out] = laff_copy(x,y)
[row_x, col_x] = size(x);
[row_y, col_y] = size(y);

if (row_x ~= 1 && col_x ~= 1) ||  (row_y ~= 1 && col_y ~= 1)
    disp('FAILED');
    y_out = 'FAILED';
    return ;
end
    
end

