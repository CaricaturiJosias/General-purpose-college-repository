function timeSpent = BubbleSort(Lista)
    swap = true;  
    tic;
    while swap
      swap = false;
      for i = 1:(size(Lista, 2))-1
        if (Lista(i) > Lista(i+1))
            swap = true;
            % Swapping
            Lista([i i+1]) = Lista([i+1 i]);
        end % If
      end % For
    end % While
    timeSpent = toc;
    subplot(2,1,2);
    stem(1:size(Lista,2), Lista);
end % Func
