function result = Merge(left,right)
    result = [];

    while (~isempty(left) && ~isempty(right))
        if left(1) <= right(1)
            result = [result left(1)];
            left = left(2:end);
        else
            result = [result right(1)];
            right = right(2:end);
        end
    end
    while ~isempty(left)
        result = [result left(1)];
        left = left(2:end);
    end
    while ~isempty(right)
        result = [result right(1)];
        right = right(2:end);
    end
end

