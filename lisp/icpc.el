(show-paren-mode 1)
(global-linum-mode t) 
(global-set-key "\C-z" 'undo)
(global-set-key "\C-r" 'query-replace)
(setq inhibit-startup-message t)
(setq-default tab-width 2 indent-tabs-mode nil)

(setq initial-frame-alist
      (append (list
	             '(top . 0)
	             '(left . 1000)
	             )
	            initial-frame-alist))
(setq default-frame-alist initial-frame-alist)


(require 'flymake)

(defun flymake-cc-init ()
  (let* ((temp-file   (flymake-init-create-temp-buffer-copy
                       'flymake-create-temp-inplace))
         (local-file  (file-relative-name
                       temp-file
                       (file-name-directory buffer-file-name))))
    (list "g++" (list "-std=c++11" "-Wall" "-Wextra" "-fsyntax-only" local-file))))

(push '("\\.\\(cpp\\)$" flymake-cc-init) flymake-allowed-file-name-masks)

(add-hook 'c++-mode-hook
          '(lambda ()
             (flymake-mode t)))

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

