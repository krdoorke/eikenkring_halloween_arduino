// Setup timers for animation
void activateAnimation() {
    timer.setTimeout(10, activate_sound2);
    timer.setTimeout(3000, activate_smoke);
    timer.setTimeout(5000, activate_stroboscoop);
    timer.setTimeout(5500, stop_sound);
    timer.setTimeout(6000, activate_sound1);
    timer.setTimeout(12000, stop_stroboscoop);
    timer.setTimeout(13000, stop_smoke);
    timer.setTimeout(16500, stop_sound);
    timer.setTimeout(17000, activate_leaf_blower);
    timer.setTimeout(20000, activate_light_effects);
    timer.setTimeout(25000, stop_leaf_blower);
    timer.setTimeout(35000, activate_sound4);
    timer.setTimeout(37000, stop_light_effects);
    timer.setTimeout(45000, stop_sound);
}

void activateBackgroundSound() {
    timer.setTimeout(100, activate_sound3);
}
