// src/hooks/useChessSounds.js
import { useEffect, useRef } from 'react';


const moveSound = '/sound/move-self.mp3';  // Simple public path
const captureSound = '/sound/move-self.mp3'; // Different file for capture sound?
const useChessSounds = () => {

    // Stores mutable values that persist between renders without triggering re-renders.
    const audioRefs = useRef({
        move: null,
        capture: null,
        // Add more sounds here
    });

    // Runs only once..... Empty dependency array means this only runs once.
    useEffect(() => {
        // Initialize all audio objects
        audioRefs.current.move = new Audio(moveSound);
        audioRefs.current.capture = new Audio(captureSound);

        const preload = (audio) => {
            audio.volume = 0.5; // Default volume
            audio.load();
        };

        Object.values(audioRefs.current).forEach(preload);

        // Deconstrucotor Basically.
        return () => {
            // Cleanup all audio objects
            Object.values(audioRefs.current).forEach(audio => {
                if (audio) {
                    audio.pause();
                    audio.src = ''; // Helps with garbage collection
                }
            });
        };
    }, []);


    const playSound = (type) => {
        const audio = audioRefs.current[type];
        if (!audio) return;

        audio.currentTime = 0; // Rewind
        audio.play().catch(e => console.warn('Audio play failed:', e));
    };

    return {
        playMove: () => playSound('move'),
        playCapture: () => playSound('capture'),
        // Add more sound controls as needed
    };
};

export default useChessSounds;