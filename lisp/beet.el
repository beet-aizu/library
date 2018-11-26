(defun beet ()
  (interactive)
  (setq pos (point))
  (goto-char (point-min))
  (goto-char (- (search-forward "//INSERT ABOVE HERE") 19))
  (let (file buf str from to)
    (setq file (read-file-name "File Name: " "~/git-library/"))
    (setq buf (find-file-noselect file))
    (setq str
	  (with-current-buffer buf
	    (buffer-substring-no-properties (point-min) (point-max))))
    (setq from (+ (string-match "//BEGIN CUT HERE" str) 17))
    (setq to (+ (string-match "//END CUT HERE" str) 1))
    (insert
     (with-current-buffer buf
       (buffer-substring-no-properties from to)))
    (insert "\n")
    (setq pos (+ pos (- to from) 1)))
  (goto-char pos))

(define-key global-map (kbd "C-x l") 'beet)

(defun repl ()
  (interactive)
  (let ((pos (point)))
    (setq case-fold-search nil)
    (goto-char (point-min))
    (replace-regexp "\\([^a-zA-z0-9_\"]\\)int\\([^a-zA-z0-9_\"]\\)" "\\1Int\\2")
    (goto-char (point-min))
    (replace-regexp "\\([(),]\\)int\\([(),]\\)" "\\1Int\\2")
    (save-buffer)
    (mark-whole-buffer)
    (kill-ring-save (region-beginning) (region-end))
    (goto-char pos)))

(define-key global-map (kbd "C-x r") 'repl)
