<img width="940" alt="screen shot 2018-09-12 at 10 19 50" src="https://user-images.githubusercontent.com/36439765/45412002-fd2fd780-b675-11e8-9a6e-b7ce36b8e939.png">

Because Swap_push isn’t as natural

  Summary:
This project will make you sort data on a stack, with a limited set of instructions, using
the lowest possible number of actions. To succeed you’ll have to manipulate various types of 
algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |

The next 3 images show you the basic process that the algorythm follows to sort the arguments using two stacks. Using the visualiser I wrote as a bonus. can be called using "-v" flag. 

<img width="655" alt="screen shot 2018-09-12 at 10 22 30" src="https://user-images.githubusercontent.com/36439765/45412009-028d2200-b676-11e8-8cac-9c1bfe3b5c1b.png"><img width="630" alt="screen shot 2018-09-12 at 10 22 24" src="https://user-images.githubusercontent.com/36439765/45412015-04ef7c00-b676-11e8-88b4-004e9ce90686.png"> 

The screenshot below shows the visualiser once the stack has been sorted, see the OK which is the checkers output meaning that the push-swap program sorted the arguments <img width="827" alt="screen shot 2018-09-12 at 10 22 14" src="https://user-images.githubusercontent.com/36439765/45412021-0751d600-b676-11e8-9f5a-40d951832665.png">

Finally the "-s" flag shows each stack after every opperation as shown with 3 arguments.
<img width="817" alt="screen shot 2018-09-12 at 10 24 32" src="https://user-images.githubusercontent.com/36439765/45412073-1c2e6980-b676-11e8-87eb-36df548c3cc3.png">

-WE THINK CODE(CPT)
