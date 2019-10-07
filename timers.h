// Setup timers for animation
void runAnimation() {
    timer.setTimeout(10, activate_sound2);
    timer.setTimeout(3000, activate_stroboscoop);
    timer.setTimeout(5000, activate_smoke);
    timer.setTimeout(10000, stop_stroboscoop);
    timer.setTimeout(15000, stop_smoke);
    timer.setTimeout(15000, activate_sound1);
    timer.setTimeout(30000, stop_Animation);
}

void periodicalAnimation() {
    timer.setTimeout(10, activate_sound2);
    timer.setTimeout(8000, stop_Animation);
}
