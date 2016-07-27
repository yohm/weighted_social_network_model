# Weighted Social Network model

This repository is for a simulation code fo the weighted social network model.
The model was originally proposed by [Kumpula et al., "Emergence of communities in weighted networks", Phys Rev Lett. 99, 228701 (2007)](http://journals.aps.org/prl/abstract/10.1103/PhysRevLett.99.228701) and later extended by [Murase et al., "Modeling the Role of Relationship Fading and Breakup in Social Network Formation", PLoS ONE, 10(7): e0133005 (2015)](http://journals.plos.org/plosone/article?id=10.1371/journal.pone.0133005).
This code is for the extended version of the model.

# Compiling

The simulation code is written in C++ using boost library.
If you are using MacOS and homebrew, just run

```
brew install boost
```

Or you can just download the file from [the boost official page](http://www.boost.org/) since we need header files only.

This code is parallelized using OpenMP. Since the default compiler on MacOSX (clang) does not support OpenMP, you need to install gcc.

```
brew tap homebrew/versions
brew install gcc5
```

If you install boost in a different way, just specify the path of the boost when building. If you are using Linux, just use the default gcc.

To compile, just run `make`. Specify the path of the boost library by setting `BOOST_PATH` environment variable like

```
BOOST_PATH=/usr/local/include make
```

Since the makefile is very simple, you can edit it by yourself if you encountered a trouble.

# Running

The simulator has the following parameters.

- N : number of nodes
- p_delta : probability to make a link by local attachment
- p_r : probability to make a link by global attachment
- delta : the increase of the link weight during local attachment
- p_nd : probability of node deletion
- p_ld : probability of link deletion
- aging : an aging factor. At each time step, all the link weights are multiplied by this value. To disable aging, set this to 1.
- w_th : threshold to remove the link.
- t_max : simulation time step
- seed : seed of the random number generator

Specify the parameter as command line arguments.

```
./wsn.out <N> <p_delta> <p_r> <delta> <p_nd> <p_ld> <aging> <w_th> <t_max> <seed>
```

For example, if you would like to reproduce the results of the Node Deletion model in "Y. Murase et al., PLoS ONE" paper, run the following.

```
./wsn.out 10000 0.05 0.0005 1.0 0.001 0.0 1.0 0.01 25000 1234
```

To change the number of threads to use, set `OMP_NUM_THREADS` environment variables.

```
export OMP_NUM_THREADS=8
```

After you conduct the simulation, the file containing the network information `net.edg` is created.
In the file, links are denoted in each row. The first, second, and the third columns indicates the node ids and the weights respectively.

# LICENSE

The MIT License (MIT)
Copyright (c) 2016 Yohsuke Murase

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
