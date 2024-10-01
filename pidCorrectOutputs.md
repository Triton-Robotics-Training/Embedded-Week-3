On our test code, these are the outputs we got:

For a Right-Hand Riemann sum:

```
Results at time 1: P: 4.288000, I: 2.814000 D: 5.628000 All: 12.730000
Results at time 2: P: 3.660800, I: 5.216400 D: -0.823200 All: 8.054000
Results at time 3: P: 2.681600, I: 6.976200 D: -1.285200 All: 8.372600
Results at time 4: P: 1.360000, I: 7.868700 D: -1.734600 All: 7.494100
Results at time 5: P: -0.118400, I: 7.791000 D: -1.940400 All: 5.732200
Results at time 6: P: -1.452800, I: 6.837600 D: -1.751400 All: 3.633400
Results at time 7: P: -2.403200, I: 5.260500 D: -1.247400 All: 1.609900
Results at time 8: P: -2.934400, I: 3.334800 D: -0.697200 All: -0.296800
Results at time 9: P: -3.152000, I: 1.266300 D: -0.285600 All: -2.171300
Results at time 10: P: -3.200000, I: -0.833700 D: -0.063000 All: -4.096700
Results at time 11: P: -3.177600, I: -2.919000 D: 0.029400 All: -6.067200
Results at time 12: P: -3.075200, I: -4.937100 D: 0.134400 All: -7.877900
Results at time 13: P: -2.940800, I: -6.867000 D: 0.176400 All: -9.631400
Results at time 14: P: -2.681600, I: -8.626800 D: 0.340200 All: -10.968200
Results at time 15: P: -2.281600, I: -10.124100 D: 0.525000 All: -11.880700
Results at time 16: P: -1.798400, I: -11.304300 D: 0.634200 All: -12.468500
Results at time 17: P: -1.305600, I: -12.161100 D: 0.646800 All: -12.819900
Results at time 18: P: -0.860800, I: -12.726000 D: 0.583800 All: -13.003000
Results at time 19: P: -0.480000, I: -13.041000 D: 0.499800 All: -13.021200
Results at time 20: P: -0.166400, I: -13.150200 D: 0.411600 All: -12.905000
Results at time 21: P: 0.092800, I: -13.089300 D: 0.340200 All: -12.656300
Results at time 22: P: 0.304000, I: -12.889800 D: 0.277200 All: -12.308600
Results at time 23: P: 0.483200, I: -12.572700 D: 0.235200 All: -11.854300
Results at time 24: P: 0.633600, I: -12.156900 D: 0.197400 All: -11.325900
Results at time 25: P: 0.000000, I: -12.156900 D: -0.831600 All: -12.9
```

For a Left-Hand Riemann sum:

```
Results at time 1: P: 4.288000, I: 0.000000 D: 5.628000 All: 9.916000
Results at time 2: P: 3.660800, I: 2.814000 D: -0.823200 All: 5.651600
Results at time 3: P: 2.681600, I: 5.216400 D: -1.285200 All: 6.612800
Results at time 4: P: 1.360000, I: 6.976200 D: -1.734600 All: 6.601600
Results at time 5: P: -0.118400, I: 7.868700 D: -1.940400 All: 5.809900
Results at time 6: P: -1.452800, I: 7.791000 D: -1.751400 All: 4.586800
Results at time 7: P: -2.403200, I: 6.837600 D: -1.247400 All: 3.187000
Results at time 8: P: -2.934400, I: 5.260500 D: -0.697200 All: 1.628900
Results at time 9: P: -3.152000, I: 3.334800 D: -0.285600 All: -0.102800
Results at time 10: P: -3.200000, I: 1.266300 D: -0.063000 All: -1.996700
Results at time 11: P: -3.177600, I: -0.833700 D: 0.029400 All: -3.981900
Results at time 12: P: -3.075200, I: -2.919000 D: 0.134400 All: -5.859800
Results at time 13: P: -2.940800, I: -4.937100 D: 0.176400 All: -7.701500
Results at time 14: P: -2.681600, I: -6.867000 D: 0.340200 All: -9.208400
Results at time 15: P: -2.281600, I: -8.626800 D: 0.525000 All: -10.383400
Results at time 16: P: -1.798400, I: -10.124100 D: 0.634200 All: -11.288300
Results at time 17: P: -1.305600, I: -11.304300 D: 0.646800 All: -11.963100
Results at time 18: P: -0.860800, I: -12.161100 D: 0.583800 All: -12.438100
Results at time 19: P: -0.480000, I: -12.726000 D: 0.499800 All: -12.706200
Results at time 20: P: -0.166400, I: -13.041000 D: 0.411600 All: -12.795800
Results at time 21: P: 0.092800, I: -13.150200 D: 0.340200 All: -12.717200
Results at time 22: P: 0.304000, I: -13.089300 D: 0.277200 All: -12.508100
Results at time 23: P: 0.483200, I: -12.889800 D: 0.235200 All: -12.171400
Results at time 24: P: 0.633600, I: -12.572700 D: 0.197400 All: -11.741700
Results at time 25: P: 0.000000, I: -12.156900 D: -0.831600 All: -12.988500
```

They are so different because these time intervals are so large, but in a case where the data is more fluid, and there are more data points per second, the difference between these two types of riemann calculation would be subtstantially smaller. You can experiment with this exact data set here: [Rieman Sum Simulator](https://www.desmos.com/calculator/kye17rgo1b)

If you happen to do a trapezoidal Riemann sum, the Integral would be the average of these two values.
