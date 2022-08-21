Hmm; after having a look at the others solution; i saw most of the users reversing the input without changing the datatype to `str`.
​
Nice strategy! They store the results in `long long` datatype and then hard check whether this reversed thing is in the range of `INT_MIN` and `INT_MAX`.
​
But i am also happy with my solution. If stoi throws an exception, catch it and return 0 .
​
XD