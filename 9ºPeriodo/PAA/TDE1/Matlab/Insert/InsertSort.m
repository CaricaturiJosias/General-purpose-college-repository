function timeSpent = InsertSort(Lista)
    tic;
    subplot(2,1,2);
    for i =  1:size(Lista,2)+1
        j = i-1;
        while (j > 1) && (Lista(j-1) > Lista(j))
            % Swapping
            Lista([j-1 j]) = Lista([j j-1]);
            j = j-1;
        end
    end
    timeSpent = toc;

    stem(1:size(Lista,2), Lista);
end % Func
