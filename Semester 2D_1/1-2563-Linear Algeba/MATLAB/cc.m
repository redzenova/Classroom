function [y_out] = omg(a,x,y)
[a_r,a_c] = size(a);
[x_r,x_c] = size(x);
[y_r,y_c] = size(y);
if(a_c == x_r & a_r == y_r)
    for i = 1:a_r
        for j = 1:a_c
            y(i,1) = a(i,j)*x(j,1)+y(i,1);
        end
    end
else
    y_out = 'FAILED';
    return
end
y_out = y;
return
end
