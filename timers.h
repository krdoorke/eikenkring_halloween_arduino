// Setup timers for animation
void activateAnimation() {
    timer.setTimeout(10, activate_sound2);
    timer.setTimeout(3000, activate_stroboscoop);
    timer.setTimeout(5000, activate_smoke);
    timer.setTimeout(5500, stop_sound);
    timer.setTimeout(6000, activate_sound1);
    timer.setTimeout(10000, stop_stroboscoop);
    timer.setTimeout(15000, stop_smoke);
    timer.setTimeout(15500, stop_sound);
}

void activateBackgroundSound() {
    timer.setTimeout(100, activate_sound3);
}
