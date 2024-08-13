This is Week 3's PID video:

In this video we're going over PID.

> TITLE CARD: PID ^

PID is an art, but more realistically, PID is an algorithm (TODO)

As an engineer, the actual movements of any machine is rarely precisely the same as we desire. Thus, we need some ways to approximate the state of the machine so that it is as close as possible to how we want our machines to move. PID is an algorithm that allows us to adjust to out desired state given the machine's previous behaviors.

> IDK TODO (SHIRLEY PICK SMTH) ^

Before we delve into the specifics of PID, here are some terminologies:

The desired state is where we want the system to be

The actual state is where the system is, this is gotten through a sensor of some kind (PID is closed-loop system, and thus requires feedback to operate).

The error of the system is the desired minus actual. This is how far the actual state of the system is deviated from the desired.

The output is how we actuate the system. This is generally our only method of actuating the system, and is often not relatable to the inputs we get from the system, an example being that we want to control position of a motor but all we can actually set is its acceleration.

Remember that PID is an algorithm that helps us control the variable we care about with separate actuation, and is used in cases where the only way we can actuate the system doesn't give us way to control the system well.

> TERMINOLOGY CARD, ALL THE TERMS ^

The first way we can make a system do what we want is with the proportional component. The proportional component will set an output directly proportional to the error, as such $O_p(t) = k_p * e(t)$. In this case, $k_p$ is our multiplier for p, and it is one of the parameters we use to tune the system.

Let's take an example of a motor, with which we are trying to control its position. Let's say we have a motor at position 10, and we want to be at 3, with this, our error e(t) is desired - actual, which is 3 - 10, giving us an error of -7. If we have a $k_p$ value of 12, then the value that is sent the motor is -84.

These are all arbitrary units, and that makes sense because the scale of the PID depeends on the method of your measurment (what is 10 and what is 3, meters? cm? degrees?), and the method of actuation (What is -84, is that in amps, mA, percent, or some other unit). Remember that the scale of a PID will differ wildly on these factors.

> INCLUDE P EQUATION PLUS A DIAGRAM? A VISUAL? OF SOME SORT IDK ^

One thing to note is that, it takes time for machines to interpret and execute the instructions in reality. Unlike our graphs which looks like they are continuous, the actual values are obtained and calculated in discrete time stamps. This means that we will need to use estimation methods to calculate the derivatives and integrals of e(t) for the following I and D componenets. 

> GRAPH SHOWING ACTUAL OUTPUT VS DESIRED ZOOMED IN SHOWING CONNECTION

Now, what if we apply -84 power to the motor, and it reached 3. According to the equation, our desired is 3, our actual is 3, and therefore our error is 0 and our output is 0. Fantastic. HOWEVER, the system attached to the motor has inertia, and that inertia carries the motor past 3 and all the way to -1, before the force of the motor becomes enough to pull the system to a halt and make it begin moving in the other direction. Now its moving higher, until again it reaches 0 and the output is again 0 and then it goes past AGAIN to 4, and back, and forth, until it slowly stabilizes at 3.

This phenomenon is known as overshoot, and it happens with virtually any amount of unchecked inertia in your system. There is a way to combat this, and this comes in the form of the D component, or the derivative component. The derivative component will set an output directly proportional to the error, as such $O_d(t) = k_d * \frac{de(t)}{dt}$. On its own, all it does is resist change of the actual, but with P and D, you can create systems that move the actual toward the desired and smooth out oscillations. If we go back to our scenario from earlier, lets say that we now have a $k_d$ of 1.2. Now, we should also quantify the



Combining all three componenets, the PID equaiton:

$$
O(t) = k_pe(t) + k_i \int{e(t)dt} + k_d\frac{de(t)}{dt}
$$

TOPICS TO DISCUSS:

- What is PID? Why do we use it, what is the goal?
- First of all, terminology we should keep in track
- desired: where you want something to be (fixed color graph) (d(t))
- actual: where it is (another fixed color graph) a(t)
- error: `desired - actual` e(t)
- output: the value you give the motor? to make it do (the actuation), result of the current PID calculation O(t)
- time stamp: the time value used to distinguish between each cycle of code executed
- P component $ k_p $
- - proportional
- - reacts based on how far the desired is from the actual at the current time stamp
- I compuonenet
- - integral of the error
- - reacts in a cumulative fashion to the integral of error over time (slow build, will go up if the error is + and go down if the error is -)
- D component
- - differentiation
- - reacts based on the difference between the current and the previous time stamps (the slope), aka: how fast is the desired approaching the actual
- Feed forward
- - external equation or input to the output
- - can be set up to be based on external data or to be a static addition, or even a multiplier on the desired itself
- - very flexible, and is very diffeent from system to system
- - meant to react directly with knowledge you have about the system

EXAMPLES USING ALL COLLECTIVELY:
Flywheel P AND I
Turret Control (P D and FF )
