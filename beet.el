(defun beet () 
  (interactive) 
  (let (file buf str from to) 
    (setq file (read-file-name "File Name: " "~/git-library/"))
    (setq buf (find-file-noselect file))
    (setq str
	  (with-current-buffer buf
	    (buffer-substring-no-properties (point-min) (point-max))))
    (setq from (search "//BEGIN CUT HERE" str))
    (setq to (search "//END CUT HERE" str))
    (insert 
	  (with-current-buffer buf
	    (buffer-substring-no-properties (+ from 17) (+ to 1))))
    (insert "\n")))

(define-key global-map (kbd "C-x l") 'beet)

