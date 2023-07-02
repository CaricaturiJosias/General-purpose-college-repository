function timeSpent = SelectSort(Lista)
    tic
    for i = 1:(size(Lista,2)-1)
        min_index = i;
        for j = (i+1):(size(Lista,2))
            if(Lista(j) < Lista(min_index)) 
                min_index  = j;
            end
        end
        if (i ~= min_index)
            Lista([i min_index ]) = Lista([min_index  i]);
        end
    end
    timeSpent = toc;
    subplot(2,1,2);
    stem(0:(size(Lista,2)-1), Lista);
end