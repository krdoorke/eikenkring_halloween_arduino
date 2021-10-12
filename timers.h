// Setup timers for animation
void activateAnimation() {
    sound_timer.setTimeout(10, activate_sound2);
    sound_timer.setTimeout(3000, stop_sound);
    animation_timer.setTimeout(4000, activate_smoke);
    animation_timer.setTimeout(13000, stop_smoke);
    sound_timer.setTimeout(14000, activate_sound1);
    sound_timer.setTimeout(20000, stop_sound);
    animation_timer.setTimeout(21000, activate_stroboscoop);
    animation_timer.setTimeout(29000, stop_stroboscoop);
    animation_timer.setTimeout(30000, activate_leaf_blower);
    animation_timer.setTimeout(37000, stop_leaf_blower);
    animation_timer.setTimeout(40000, activate_light_effects);
    sound_timer.setTimeout(50000, activate_sound4);
    animation_timer.setTimeout(55000, stop_light_effects);
    sound_timer.setTimeout(60000, stop_sound);
}

void activateBackgroundSound() {
    sound_timer.setTimeout(100, activate_sound3);
}
