% Copyright 2020 The University of Texas at Austin
%
% For licensing information see
%                http://www.cs.utexas.edu/users/flame/license.html 
%                                                                                 
% Programmed by: Name of author
%                Email of author

function [ A_out ] = set_to_identity_LR_unb( A )

  [ AL, AR ] = FLA_Part_1x2( A, ...
                               0, 'FLA_LEFT' );

  while ( size( AL, 2 ) < size( A, 2 ) )

    [ A0, a1, A2 ]= FLA_Repart_1x2_to_1x3( AL, AR, ...
                                         1, 'FLA_RIGHT' );

    %------------------------------------------------------------%
    X = size(AL);
    
    a1 = laff_unitv(a1, X(2)+1);

    %------------------------------------------------------------%

    [ AL, AR ] = FLA_Cont_with_1x3_to_1x2( A0, a1, A2, ...
                                           'FLA_LEFT' );

  end

  A_out = [ AL, AR ];

return