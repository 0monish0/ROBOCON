'''
Create your very own map function. Your map function will have the same syntax as we have in embedded C
(Syntax: map(value , in_range_start , in_range_end , out_range_start , out_range_end))
You can create this function in any programmimg language.
End goal : derive the formula and implement it in a function.

derivaiton explanation:
1. First, we need to find the ratio of the input value within its range:
   ratio = (value - in_min) / (in_max - in_min)
2. Then, we scale this ratio to the output range:
    scaled_value = ratio * (out_max - out_min)
3. Finally, we shift this scaled value to start from out_min:
    mapped_value = scaled_value + out_min
Combining these steps, we get the formula:  
mapped_value = (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
'''

def map(value, in_min, in_max, out_min, out_max):
    mv = (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
    return mv

print(map(5, 0, 10, 0, 100))  
print(map(2.5, 0, 10, 0, 100))
