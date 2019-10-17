;BEGIN CUT HERE
(show-paren-mode 1)
(global-linum-mode t)
(global-set-key "\C-z" 'undo)
(global-set-key "\C-r" 'query-replace)
(setq-default tab-width 2 indent-tabs-mode nil)
(setq inhibit-startup-message t)

(setq initial-frame-alist
      (append (list '(top . 0) '(left . 750))
              initial-frame-alist))

(setq default-frame-alist initial-frame-alist)
(add-hook 'before-save-hook 'delete-trailing-whitespace)

(require 'flymake)

(defun flymake-cc-init ()
  (let* ((temp-file   (flymake-init-create-temp-buffer-copy
                       'flymake-create-temp-inplace))
         (local-file  (file-relative-name
                       temp-file
                       (file-name-directory buffer-file-name))))
    (list "g++" (list "-std=c++14"
                      "-Wall"
                      "-Wextra"
                      "-fsyntax-only"
                      local-file))))

(push '("\\.\\(cpp\\)$" flymake-cc-init)
      flymake-allowed-file-name-masks)

(add-hook 'c++-mode-hook
          '(lambda ()
             (flymake-mode t)))

(defun repl ()
  (interactive)
  (let ((pos (point)))
    (setq case-fold-search nil)
    (goto-char (point-min))
    (replace-regexp "\\([^a-zA-Z0-9_\"]\\)int\\([^a-zA-Z0-9_\"]\\)"
                    "\\1Int\\2")
    (goto-char (point-min))
    (replace-regexp "\\([(),]\\)int\\([(),]\\)" "\\1Int\\2")
    (save-buffer)
    (mark-whole-buffer)
    (kill-ring-save (region-beginning) (region-end))
    (goto-char pos)))

(define-key global-map (kbd "C-x r") 'repl)

(defun fmt ()
  (interactive)
  (let ((pos (point)))
    (mark-whole-buffer)
    (indent-region (region-beginning) (region-end))
    (goto-char pos)))

(define-key global-map (kbd "C-x q") 'fmt)
;END CUT HERE
