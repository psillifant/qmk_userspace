# Flashing the sofle choc

My sofle choc uses an rp2040 based controller, not the standard promicro.  Therefore, when flashing, things are a little different to normal.

When compiling, run the following command (note that the extra `-e` argument is no longer necessary here, as I've added the relevant rule to `rules.mk` instead):

```
qmk compile -kb sofle_choc -km soflec
```

Then, to flash:
- find the `.uf2` file in the root folder of this git repo that will have been created by the above step.
- Take your sofle, hold down the farthest key on the top row, from the controller - don't release it.
- Plug in the keyboard half.  Wait 2 or 3 seconds, and only then release the key.  It should now appear in finder / your file explorer as a removable drive.
- Drag the `.uf2` file onto the new removable drive.  It should automatically disconnect the drive, and reconnect the keyboard.
- Repeat with the other half.  Note that as sofle is a mirror image on each half, the same rule applies - hold the farthest key from the controller, on the top row. 