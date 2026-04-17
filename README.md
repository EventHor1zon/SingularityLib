
# Singularity Lib


## Brief

A lightweight C event system library

### Notes below

- Creating a new event bus adds a new Event table
- Events are published to busses
- subscribers to this bus are called by the event bus
- Multiple busses can be registered
- Multiple subscibers can be registered to a single event
- Subscribers can register and deregister from an event or bus
