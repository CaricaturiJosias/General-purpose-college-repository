function Lista = MergeSort(Lista)
    if size(Lista,2) <= 1
        return;
    end
    left = [];
    right = [];

    for i = 1:size(Lista,2)
        if i < ((size(Lista,2)+1)/2)
            left = [left Lista(i)];
        else
            right = [right Lista(i)];
        end
    end

    left = MergeSort(left);
    right = MergeSort(right);
    Lista = Merge(left, right);
end